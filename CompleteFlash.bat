::////////////////////////////////////////////////////////////////////////////////////////
::
:: Script:		CompleteFlash.bat
:: Autor:		Dirceu Rodrigues Jr. - 2021
:: Descrição:	Script para completar um arquivo binário com dados aleatórios ao final
:: Uso:			CompleteFlash.bat <arquivo.bin>
:: Obs:			Alterar caminho de srec_cat.exe (../ abaixo) dependendo do contexto de
::				chamada do script; se a partir de terminal ou de post-build em IDE.
::				Exemplo de comando de post-build em IDE STM32CubeIDE, assumindo que o
::				arquivo binário está em Release ou Debug e que os arquivos "srec_cat.exe"
::				e "CompleteFlash.bat" estejam localizados um diretório acima:
::				cmd /c "..\CompleteFlash.bat" ${ProjName}.bin
::
::////////////////////////////////////////////////////////////////////////////////////////

@echo off
echo.
echo.
echo ********** GERACAO DE ARQUIVO FINAL PARA FLASH **********
echo Diretorio atual: %CD%

:: Ajusta para usar 128 kB de flash. Ex. alterar para 2097152 (2 MB)
set END_FLASH=131072

:: Verifica o número de argumentos
set nargs=0
for %%x in (%*) do (
   set /A nargs+=1
)
if %nargs% NEQ 1 (
  echo Erro. Uso: "CompleteFlash.bat <arquivo.bin>"
  goto :terminate
)

:: Determina nome do arquivo de saída
set output_name=%~n1_full%~x1

:: Obtém o tamanho do arquivo de entrada
call :GetFileSize %1

:: Calcula o número de bytes aleatórios adicionais a preencher
set /a diff=END_FLASH-source_size

:: Chama "srec_cat.exe"
echo Gerando arquivo binario "%output_name%"
..\srec_cat.exe %1 -Binary -random-fill %source_size% %END_FLASH% --o %output_name% -Binary
if %ERRORLEVEL% NEQ 0 (
  echo Erro executando "srec_cat.exe"  
) else (
  echo Sucesso
  echo Tamanho original: %source_size% bytes
  echo Tamanho final: %END_FLASH% bytes
  echo Bytes aleatorios adicionados: %diff%
)

goto :terminate

:GetFileSize
  set source_size=%~z1
  exit /b 0
  
:terminate
  echo Fim!