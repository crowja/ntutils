#! /usr/bin/env python3

def _in_common(l1, l2):
    count = 0
    for i in range(len(l1)):
        if l1[i] in l2:
            count += 1
    return count


bases = [
    ["A", ["A"]],
    ["C", ["C"]],
    ["G", ["G"]],
    ["T", ["T"]],
    ["R", ["A", "G"]],
    ["Y", ["C", "T"]],
    ["S", ["C", "G"]],
    ["W", ["A", "T"]],
    ["K", ["G", "T"]],
    ["M", ["A", "C"]],
    ["B", ["C", "G", "T"]],
    ["V", ["A", "C", "G"]],
    ["D", ["A", "G", "T"]],
    ["H", ["A", "C", "T"]],
    ["N", ["A", "C", "G", "T"]],
]

print("#include \"ntmatch.h\"\n")
print("double ntmatch(char b1, char b2, double penalty) {")
print("double s;")
print("")
print("switch(b1) {")
for i in range(len(bases)):
    b1 = bases[i][0]
    l1 = bases[i][1]
    print(f"   case \'{b1}\':")
    print(f"   case \'{b1.lower()}\':")
    if b1 == "N":
        print(f"   default:")
    if b1 == "T":
        print(f"    case \'U\':")
        print(f"    case \'u\':")
    print("      switch(b2) {")
    for j in range(len(bases)):
        b2 = bases[j][0]
        l2 = bases[j][1]
        # Figure out how many elements l1 and l2 have in common
        ncommon = _in_common(l1, l2)
        ntotal = len(l1) * len(l2)
        print(f"         case \'{b2}\':")
        print(f"         case \'{b2.lower()}\':")
        if b2 == "N":
            print(f"         default:")
        if b2 == "T":
            print(f"         case \'U\':")
            print(f"         case \'u\':")
        print(f"s = ({ncommon} - {ntotal - ncommon} * penalty) / (double) {ntotal};")
        print("         break;")
    print("}")
    print("break;")
print("}")
print("return s;")
print("}")

