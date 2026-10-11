
@echo off
setlocal
title Compilar e executar - Projeto Raylib

cd /d "%~dp0"

echo ==========================================
echo   Compilando projeto C com Raylib
echo ==========================================
echo.

REM Procurar o GCC em uma pasta local opcional
REM Link para baixar w64devkit - https://github.com/skeeto/w64devkit/releases
set "GCC="
if exist "tools\w64devkit\bin\gcc.exe" (
    set "GCC=%CD%\tools\w64devkit\bin\gcc.exe"
)

REM Procurar o GCC no PATH
if not defined GCC (
    for /f "delims=" %%G in ('where gcc 2^>nul') do (
        if not defined GCC set "GCC=%%G"
    )
)

REM Verificar se o compilador foi encontrado
if not defined GCC (
    echo ERRO: GCC nao encontrado.
    echo Instale o w64devkit ou configure o PATH.
    pause
    exit /b 1
)

REM Verificar se a biblioteca Raylib existe
if not exist "src\include\raylib\lib\libraylib.a" (
    echo ERRO: Biblioteca Raylib nao encontrada.
    echo Verifique src\include\raylib\lib.
    pause
    exit /b 1
)

REM Compilar todos os arquivos C da pasta src
"%GCC%" -std=c99 src\*.c -o main.exe -O1^
    -Isrc\include ^
    -Isrc\include\raylib\include ^
    -Lsrc\include\raylib\lib ^
    -lraylib -lopengl32 -lgdi32 -lwinmm -static

REM Verificar se a compilacao falhou
if errorlevel 1 (
    echo.
    echo ERRO: A compilacao falhou.
    pause
    exit /b 1
)

echo.
echo Compilacao concluida com sucesso!
echo Iniciando o jogo...
echo.

REM Executar o jogo a partir da raiz do projeto
main.exe

if errorlevel 1 (
    echo.
    echo O jogo terminou com um codigo de erro.
    pause
)

endlocal