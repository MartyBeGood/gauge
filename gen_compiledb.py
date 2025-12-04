import os

Import("env")

build_env_name = env["PIOENV"]

# os.system(f'mkdir -p .lsp/{build_env_name}')
print(f"Building compile_commands for {build_env_name}")

env.Replace(COMPILATIONDB_INCLUDE_TOOLCHAIN=True)
env.Replace(COMPILATIONDB_PATH=os.path.join(".lsp", build_env_name, "compile_commands.json"))
os.system(f'yq -i ".CompileFlags.CompilationDatabase = \\".lsp/{build_env_name}/\\"" .clangd')
