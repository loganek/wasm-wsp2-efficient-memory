#!/bin/bash
set -e

WASI_SDK_PREFIX="${WASI_SDK_PREFIX:-/opt/wasi-sdk}"
RUNTIME_PATH="${RUNTIME_PATH:-wasmtime}"

wit-bindgen c --autodrop-borrows=yes world.wit

$WASI_SDK_PREFIX/bin/clang imports.c libc.c main.c adapter.c user_allocator.c -o main.wasm

wasm2wat main.wasm > main.wat

$RUNTIME_PATH main.wasm
