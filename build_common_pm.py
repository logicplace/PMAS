import itertools
import os
import re

reg_8bit = {"A", "B", "L", "H", "BR", "EP", "XP", "YP", "CB", "NB", "SC", "CC"}
reg_16bit = {"BA", "HL", "IX", "IY", "PC", "SP"}

register_map = {
	"BR": ["N", "NN"],
	"NB": ["U"],
	"CB": ["V"],
	"EP": ["I"],
	"XP": ["XI"],
	"YP": ["YI"],
	"IX": ["X", "X1"],
	"IY": ["Y", "X2"],
	"SC": ["F", "FLAGS"],
}

mnemonic_map = {
	"ADC": ["ADDC"],
	"CP": ["CMP"],
	"LD": ["MOV"],
	"CPL": ["NOT"],
	"PACK": ["BCDE"],
	"UPCK": ["BCDD", "UNPACK"],
	"SWAP": ["BCDX"],
	"RETE": ["RETI"],
	"RETS": ["RETSKIP"],
	"RL": ["ROLC"],
	"RLC": ["ROL"],
	"RR": ["RORC"],
	"RRC": ["ROR"],
	"SLA": ["SAL"],
	"SRA": ["SAR"],
	"SLL": ["SHL"],
	"SRL": ["SHR"],
	"SLP": ["STOP"],
	"SBC": ["SUBC"],
	"BIT": ["TST", "TEST"],
	"EX": ["XCHG"],
}

instruction_map = {
	"CARS ~0": ["CALLB ~0"],
	"CARL ~0": ["CALL ~0", "CALLW ~0"],
	"INT [~0]": ["INT ~0", "CINT ~0"],
	"ADC BA,~0": ["CMPNW BA,~0"],
	"ADC HL,~0": ["CMPNW HL,~0"],
	"SBC IX,~0": ["CMPNW X,~0", "CMPNW X1,~0"],
	"SBC IY,~0": ["CMPNW Y,~0", "CMPNW X2,~0"],
	"DIV": ["DIV HL,A"],
	"SEP": ["EX BA,A", "EXTS BA,A"],
	"DJR NZ,~0": ["JDBNZ ~0"],
	"JP [~0]": ["JINT ~0"],
	"JRS ~0": ["JMPB ~0"],
	"JRL ~0": ["JMP ~0", "JMPW ~0"],
	"JP HL": ["JMP HL"],
	"LD A,EP": ["MOVX A,HL"],
	"LD A,XP": ["MOVX A,X", "MOVX A,X1"],
	"LD A,YP": ["MOVX A,Y", "MOVX A,X2"],
	"LD EP,A": ["MOVX HL,A"],
	"LD EP,~0": ["MOVX HL,~0"],
	"LD XP,A": ["MOVX X1,A"],
	"LD XP,~0": ["MOVX X1,~0"],
	"LD YP,A": ["MOVX X2,A"],
	"LD YP,~0": ["MOVX X2,~0"],
	"MLT": ["MUL L,A"],
	"POP ALL": ["POPA"],
	"POP ALE": ["POPAX"],
	"POP EP": ["POPX HL"],
	"POP IP": ["POPX", "POPXXX"],
	"PUSH ALL": ["PUSHA"],
	"PUSH ALE": ["PUSHAX"],
	"PUSH EP": ["PUSHX HL"],
	"PUSH IP": ["PUSHX", "PUSHXXX"],
}

case_map = {
	"C": "C", "NC": "NC",
	"Z": "Z", "NZ": "NZ",
	"LT": "L", "LE": "LE",
	"GT": "G", "GE": "GE",
	"V": "O", "NV": "NO",
	"M": "S", "P": "NS",
	"F0": "F0", "NF0": "NF0",
	"F1": "F1", "NF1": "NF1",
	"F2": "F2", "NF2": "NF2",
	"F3": "F3", "NF3": "NF3",
}
long_cases = {"C", "NC", "Z", "NZ"}
cased_mnemonics = {"CARS": "CALL", "CARL": "CALL", "JRS": "J", "JRL": "J"}

op_no_bw = {"INT", "CALL", "JP"}
op_no_bw.update(cased_mnemonics.keys())

argument_fmt = r"\w+|~\d+|\[[^\]]+\]"
cmd_parser = re.compile(r"^(\w+)(?: ({0})(?:,({0}))?)?$".format(argument_fmt))
op_parser = re.compile(r"([+:])")


def get_cased_mnemonics(mnemonic, check):
	ret = cased_mnemonics[mnemonic]
	if mnemonic.endswith("S"):
		if check not in long_cases:
			return [ret + "{}", ret + "{}B"]
		else:
			return [ret + "{}B"]
	return [ret + "{}", ret + "{}W"]

def parse_cmd(cmd):
	mnemonic, param1, param2 = cmd_parser.match(cmd).groups()
	return mnemonic, [
		op_parser.split(p[1:-1]) if p.startswith("[") else p
		for p in (param1, param2)
		if p
	]

def permutate_cmd(mnemonic, params):
	if (
		mnemonic in cased_mnemonics
		and params
		and isinstance(params[0], str)
		and params[0] in case_map
	):
		check = params.pop(0)
		cases = (check, case_map[check]) if check != case_map[check] else (check,)
		mres = ["{} {},".format(mnemonic, c) for c in cases]
		for m in get_cased_mnemonics(mnemonic, check):
			mres.extend(
				m.format(c)
				for c in cases
				if not m.startswith("J{}") or c not in "MP"
			)
	else:
		mres = [mnemonic] + mnemonic_map.get(mnemonic, [])
		if params and mnemonic not in op_no_bw:
			if any(p in reg_16bit for p in params if isinstance(p, str)):
				mres += [m + "W" for m in mres]
			else:
				mres += [m + "B" for m in mres]
	res = [mres] + permutate_params(params)

	ret = itertools.product(*res)
	return ret

def permutate_params(params, isindexing=False):
	res = []
	for p in params:
		if isinstance(p, list):
			res.append(list(permutate_params(p, isindexing=True)))
		elif isindexing and p == ":":
			# alias BR:nn and N+nn
			res.append([":", "+"])
		else:
			res.append([p] + register_map.get(p, []))

	return itertools.product(*res) if isindexing else res

def fmt_cmd(mnemonic, params):
	ret = ""
	if params:
		ret = ("" if mnemonic.endswith(",") else " ") + ",".join(
			"".join(p).join("[]") if isinstance(p, tuple) else p
			for p in params
		)
	return mnemonic + ret

try: os.mkdir("cpu/pm")
except: pass

with open("cpu/s1c88/s1c88.s", "rt") as fin, open("cpu/pm.s", "wt") as fout:
	out = []
	fout.write("; Automatically generated file, edit cpu/s1c88/s1c88.s instead\n")
	for line in fin:
		if line.startswith(".instruction"):
			assert line[13] == '"'
			endcmd = line.find('"', 14)
			cmd = line[14:endcmd]
			args = line[endcmd+1:]

			if cmd in instruction_map:
				# Wholesale aliases
				for x in instruction_map[cmd]:
					out.append('.instruction "{}"{}'.format(x, args))

			# Permutate registers and stuff
			for res in permutate_cmd(*parse_cmd(cmd)):
				mnemonic = res[0]
				params = res[1:]
				out.append('.instruction "{}"{}'.format(fmt_cmd(mnemonic, params), args))

	# Extra lines
	out.append('.instruction "MOVW NN,~0",0x01,0xB4,2,1,8,0x020250	; 1704\n')

	fout.writelines(sorted(out))
