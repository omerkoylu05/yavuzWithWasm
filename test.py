import wasmtime

engine=wasmtime.Engine()
store=wasmtime.Store(engine)
# Load the Wasm module
module = wasmtime.Module.from_file(engine,'factorial.wasm')
instance=wasmtime.Instance(store,module,[])
# Get a reference to the exported function
my_wasm_function=None
for i in module.exports:
    if i.name=="testStr":
        my_wasm_function = i.value
        break

# Define the char array you want to pass
char_array = "Hello, World!"

# Convert the char array to a Wasm compatible format
# Specify the memory limits
memory_limits = wasmtime.Limits(1, None)  # Minimum of 1 page, maximum is not specified here

# Create the memory type with the specified limits
memory_type = wasmtime.MemoryType(memory_limits)

# Create the memory instance
memory = wasmtime.Memory(store, memory_type)

# Convert the char array to a Wasm compatible format
char_array_bytes = char_array.encode("utf-8")

# Get the current memory size
current_memory_size = memory.size

# Calculate the required additional memory size
required_memory_size = current_memory_size(store) + (len(char_array_bytes) // 65536) + 1

# Grow the memory to the required size
memory.grow(store,required_memory_size)

# Get the memory buffer
memory_buffer = memory.data_ptr(store)

# Write the contents of the char array to the memory buffer
for i, byte in enumerate(char_array_bytes):
    memory_buffer[current_memory_size(store) + i] = byte

# Pass the converted char array as a parameter to the Wasm function
my_wasm_function(memory_buffer)

# Release the memory allocated for the converted char array
# memory_buffer.release()
