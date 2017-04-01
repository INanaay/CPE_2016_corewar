rm my_test abel_test
rm *.cor
../asm $1
../asm2 $2
var0=${1%%??}
var1=${2%%??}
xxd $var0.cor > my_test
xxd $var1.cor > abel_test
diff abel_test my_test
