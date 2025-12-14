{
  description = "C++ & CUDA Development Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.11";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs {
          inherit system;
          config.allowUnfree = true;
        };

        clangdWrapped = pkgs.writeShellScriptBin "clangd" ''
          export GCC_DIR="${pkgs.gcc.cc}"
          export GCC_VER="${pkgs.gcc.version}"

          export CPATH="$GCC_DIR/include/c++/$GCC_VER:$GCC_DIR/include/c++/$GCC_VER/${pkgs.stdenv.hostPlatform.config}:${pkgs.glibc.dev}/include:${pkgs.linuxHeaders}/include:$CPATH"
          export CPLUS_INCLUDE_PATH="$GCC_DIR/include/c++/$GCC_VER:$GCC_DIR/include/c++/$GCC_VER/${pkgs.stdenv.hostPlatform.config}:${pkgs.glibc.dev}/include:${pkgs.linuxHeaders}/include:$CPLUS_INCLUDE_PATH"

          exec ${pkgs.llvmPackages.clang-unwrapped}/bin/clangd \
            --query-driver=${pkgs.gcc}/bin/g++ \
            "$@"
        '';

        tools = [
          pkgs.gcc

          # Build Systems
          pkgs.cmake
          pkgs.ninja
          pkgs.gnumake

          # pkgs.cudatoolkit
          # pkgs.linuxPackages.nvidia_x11

          # Dev tools
          pkgs.gdb
          clangdWrapped
          pkgs.valgrind
        ];
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = tools;
        };

        packages.tools = pkgs.buildEnv {
          name = "cuda-tools";
          paths = tools;
        };

        defaultPackage = self.packages.${system}.tools;
      }
    );
}
