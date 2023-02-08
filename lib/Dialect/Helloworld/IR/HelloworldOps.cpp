
#include "mlir/IR/OpImplementation.h"

#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldDialect.h"
#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldOps.h"

#define GET_OP_CLASSES
#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldOps.cpp.inc"
