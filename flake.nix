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
          pkgs.clang-tools
          pkgs.valgrind
        ];
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = tools;

          shellHook = ''
            echo "GCC + CUDA Environment Active."
            # export CUDA_PATH=${pkgs.cudatoolkit}
            # export EXTRA_LDFLAGS="-L/lib -L${pkgs.linuxPackages.nvidia_x11}/lib"
            export EXTRA_CCFLAGS="-I/usr/include"
            # export LD_LIBRARY_PATH=/run/opengl-driver/lib:/run/opengl-driver-32/lib:${pkgs.lib.makeLibraryPath tools}:$LD_LIBRARY_PATH
          '';
        };

        packages.tools = pkgs.buildEnv {
          name = "cuda-tools";
          paths = tools;
        };

        defaultPackage = self.packages.${system}.tools;
      }
    );
}
