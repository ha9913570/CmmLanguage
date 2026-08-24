# ソースコードをUTF-8で読み込むようにする
add_compile_options(/source-charset:utf-8)
# 実行ファイルはShift-JISを使用する
add_compile_options(/execution-charset:.932)
# CMakeの最低バージョンを指定
cmake_minimum_required(VERSION 3.13)
# プロジェクト名と使用する言語を指定
project(CmmLanguage CXX)
# srcディレクトリの全てのcppファイルをコンパイル対象にする
file(GLOB SOURCES "src/*.cpp")
# cmmという実行ファイルを生成する
add_executable(cmm ${SOURCES})
# includeディレクトリを指定
target_include_directories(cmm PRIVATE include)
