# beginner-compiler
This repository is used to study compiler technology based on MLIR. Mainly concentrated in the following aspects:

- Code Scaffolding Toolchain (CMake,Code Standards,Software Dependency Management, etc)
- Language Binding Technology (Pybind,etc)
- MLIR
- MLIR-Extension (torch-mlir,onnx-mlir)
- Compiler based MLIR (IREE, CIRCT)
- Compiler Optimization Theory

### Build Project
STEP 1. Build Third Party Package

STEP 2. Build Beginner Compiler Project

``` bash
mkdir build

cd build

cmake -G Ninja .. \
  -DLLVM_DIR=$PWD/../third_party/llvm-project/build/lib/cmake/llvm \
  -DMLIR_DIR=$PWD/../third_party/llvm-project/build/lib/cmake/mlir \
  -DLLVM_ENABLE_ASSERTIONS=ON \
  -DCMAKE_BUILD_TYPE=RELEASE

cmake --build . --target beginner-opt
```
> PS: VSCode Debug Project
``` bash
mkdir debug
cd debug
cmake -G Ninja .. \
  -DLLVM_DIR=$PWD/../third_party/llvm-project/build/lib/cmake/llvm \
  -DMLIR_DIR=$PWD/../third_party/llvm-project/build/lib/cmake/mlir \
  -DLLVM_ENABLE_ASSERTIONS=ON \
  -DCMAKE_BUILD_TYPE=Debug

cmake --build . --target beginner-opt
```
### Run Demo
##### Demo 1: Parser MLIR file
``` bash
cd build/bin
./beginner-opt ../../example/mlir/helloworld.mlir
```

### Reference
