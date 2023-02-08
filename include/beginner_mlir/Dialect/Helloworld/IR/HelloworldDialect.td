
#ifndef HELLOWORLD_DIALECT
#define HELLOWORLD_DIALECT

include "mlir/IR/OpBase.td"

// Helloworld dialect definition.
def Helloworld_Dialect : Dialect {
  let name = "helloworld";
  let summary = "A standalone out-of-tree MLIR dialect.";
  let description = [{"This is a dialect sample based MLIR Dialect."}];
  let cppNamespace = "::beginner_mlir::helloworld";
  let hasConstantMaterializer = 1;
  let useFoldAPI = kEmitFoldAdaptorFolder;
}
// Base helloworld operation definition.
class Helloworld_Op<string mnemonic, list<Trait> traits = []> :
        Op<Helloworld_Dialect, mnemonic, traits>;
#endif // HELLOWORLD_DIALECT
