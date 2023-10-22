# -*- coding: utf-8 -*-
import wasmtime
import ctypes
import struct

store=wasmtime.Store()
engine=wasmtime.Engine()
# Load the WebAssembly module
module = wasmtime.Module.from_file(store.engine,"factorial.wasm")

s=0
imports=[]
for e in module.exports:
    if (type(e.type)==wasmtime._types.FuncType):
        s+=1
        print(s,".",e.name ,e.type.params, e.type.results)
        # item=wasmtime.Func(store,wasmtime.FuncType(e.type.params,[]),e.name)
        # imports.append(item)
# Create an instance of the module

imports=[
    wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32()],[]),"_stackRestore"),
    wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32(),wasmtime.ValType.i64(),wasmtime.ValType.i32(),wasmtime.ValType.i32()],[wasmtime.ValType.i32()]),"__start"),
    wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32(),wasmtime.ValType.i32(),wasmtime.ValType.i32(),wasmtime.ValType.i32()],[wasmtime.ValType.i32()]),"___errno_location"),
    wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32(),wasmtime.ValType.i32(),wasmtime.ValType.i32(),wasmtime.ValType.i32()],[wasmtime.ValType.i32()]),"_stackSave"),
    wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32()],[wasmtime.ValType.i32()]),"_stackAlloc"),
    wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32(),wasmtime.ValType.i32()],[wasmtime.ValType.i32()]),"_emscripten_stack_get_base"),
    wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32(),wasmtime.ValType.i32()],[wasmtime.ValType.i32()]),"_emscripten_stack_get_end"),
    # wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32()],[]),"_factorial"),
    # wasmtime.Func(store,wasmtime.FuncType([wasmtime.ValType.i32()],[]),"_testStr")
]
instance = wasmtime.Instance(store,module,imports)
# Call the factorial function
exports = instance.exports(store)
ff=exports["testStr"]
a="abc"
buf=ctypes.create_string_buffer('abc'.encode("utf-8"))
print(buf)

char_ptr=ctypes.cast(buf,ctypes.c_char_p)
int_value = struct.unpack('i', buf.raw)[0]
res=ff(store,int_value)

result_byte_array = ctypes.cast(res, ctypes.POINTER(ctypes.c_char))
result = result_byte_array[:3].decode("latin-1")

# Read the first value from the returned byte array
first_value = result[0]

# Print the first value
print(first_value)
res=ctypes.string_at(res,4)
print("sonuç:",res)
# print(f"Factorial of 5 is: {result(5)}")