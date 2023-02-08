This folder mainly is used to build third-party software. Concretely including the fellow package:

- [ ] LLVM https://github.com/llvm/llvm-project

#### build LLVM

``` bash
git clone https://github.com/llvm/llvm-project.git
mkdir -p llvm-project/build
cd llvm-project/build

cmake -G Ninja ../llvm \
   -DLLVM_ENABLE_PROJECTS="mlir" \
   -DLLVM_TARGETS_TO_BUILD="host" \
   -DLLVM_ENABLE_ASSERTIONS=ON \
   -DMLIR_ENABLE_BINDINGS_PYTHON=ON \
   -DCMAKE_BUILD_TYPE=Release \
   -DCMAKE_INSTALL_PREFIX=llvm

cmake --build . --target check-mlir
```

