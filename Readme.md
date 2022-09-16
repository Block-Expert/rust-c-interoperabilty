# How to use C library in Rust

bindgen leverages libclang to preprocess, parse, and type check C and C++ header files. It is required to use Clang 5.0 or greater.

## Installing Clang
### windows
```
Download and install the offical pre-built binary from [LLVM download page](https://releases.llvm.org/download.html).

You will also need to set (LIBCLANG_PATH) as an environment variable pointing to the bin directory fo your LLVM install.
```
### Debian-based Linuxes
```
#apt install llvm-dev libclang-dev clang
```

## Installing bindgen
```
cargo install bindgen
```
You have to add that directory to your $PATH to use bindgen

bindgen takes the path to an input C or C++ header file, and optionally an output file path for the generated bindings. If the output file path is not supplied, the bindings are printed to stdout

If we wanted to generated Rust FFI bindings from a C header named input.h and put them in the bindings.rs file, we would invoke bindgen like this:
```
$bindgen input.h -o bindings.rs
```

For more details, pass the --help flag:
```
$bindgen --help
```

## Compile and make static library

### windows
```
cl /c cool.c
lib cool.obj
rustc binding.rs
.\binding.exe

```

### linux
```
gcc -c cool.c -o cool.o
ar rcs cool.a cool.o
rustc binding.rs
./binding
```
