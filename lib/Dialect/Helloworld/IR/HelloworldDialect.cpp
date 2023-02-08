//MLIR Header
#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"
//Helloworld Dialect Header
#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldDialect.h"
#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldOps.h"

using namespace mlir;
using namespace beginner_mlir::helloworld;

#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldOpsDialect.cpp.inc"

void HelloworldDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldOps.cpp.inc"
          >();
}

void beginner_mlir::helloworld::ConstantOp::build(mlir::OpBuilder &builder, mlir::OperationState &state, double value) {
  auto dataType = RankedTensorType::get({}, builder.getF64Type());
  auto dataAttribute = DenseElementsAttr::get(dataType, value);
  beginner_mlir::helloworld::ConstantOp::build(builder, state, dataType, dataAttribute);
}

mlir::Operation *HelloworldDialect::materializeConstant(mlir::OpBuilder &builder,
                                                 mlir::Attribute value,
                                                 mlir::Type type,
                                                 mlir::Location loc) {
    return builder.create<beginner_mlir::helloworld::ConstantOp>(loc, type,
                                      value.cast<mlir::DenseElementsAttr>());
}


