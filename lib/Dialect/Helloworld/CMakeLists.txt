
file(GLOB _sources
          IR/*.cpp
    )

add_mlir_library(BEGINNERMLIRHelloworld
  ${_sources}

  ADDITIONAL_HEADER_DIRS
  ${PROJECT_SOURCE_DIR}/include/beginner_mlir/Dialect/Helloworld

  DEPENDS
	MLIRHelloworldOpsIncGen

  LINK_LIBS PUBLIC
  MLIRIR
)
