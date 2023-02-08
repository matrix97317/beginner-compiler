# COPY FROM: llvm-project/mlir/examples/standalone/standalone-opt
get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS
        ${dialect_libs}
        ${conversion_libs}
        BEGINNERMLIRHelloworld
        )
add_llvm_executable(beginner-opt beginner-opt.cpp)

llvm_update_compile_flags(beginner-opt)
target_link_libraries(beginner-opt PRIVATE ${LIBS})

mlir_check_all_link_libraries(beginner-opt)
