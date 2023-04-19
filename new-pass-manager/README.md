```
mkdir build
cd build
cmake ..
make
cat <<EOF
define i32 @add(i32 %a, i32 %b) {
entry:
  %sum = add i32 %a, %b
  ret i32 %sum
}

define i32 @main() {
entry:
  %res = call i32 @add(i32 2, i32 3)
  ret i32 %res
}
EOF
opt-10 -load-pass-plugin=./libHelloLLVM.so -passes="hello-llvm" test.ll > out.ll
cat out.ll
```