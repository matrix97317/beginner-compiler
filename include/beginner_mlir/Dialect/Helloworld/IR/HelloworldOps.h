#ifndef HELLOWORLD_HELLOWORLDOPS_H
#define HELLOWORLD_HELLOWORLDOPS_H
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#define GET_OP_CLASSES
#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldOps.h.inc"

#endif // HELLOWORLD_HELLOWORLDOPS_H
