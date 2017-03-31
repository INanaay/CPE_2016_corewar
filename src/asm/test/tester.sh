../asm $0
../asm2 $1
rm *.cor
rm my_test
rm abel_test
var0=$0
var1=$1
var0=${var0:}
var0="$var0.cor"
var1="$var1.cor"
xxd -b ${var0%.cor} > my_test
xxd -b ${var1%.cor} > abel_test
diff abel_test my_test
