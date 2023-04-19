#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

using namespace llvm;

namespace {
class BlirioLLVMPass : public PassInfoMixin<BlirioLLVMPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM) {
    errs() << "Hello, LLVM! Running on function: " << F.getName() << '\n';
    return PreservedAnalyses::all();
  }
};
} // end anonymous namespace

extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK
llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "HelloLLVM", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef PassName, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (PassName == "hello-llvm") {
                    FPM.addPass(BlirioLLVMPass());
                    return true;
                  }
                  return false;
                });
          }};
}
