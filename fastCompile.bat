:: Compila o código -- Se quiser já testar e excluir tira o '-' no GAME
gcc .\src\*.c -lpdcurses -I.\include\ -o -GAME
:: Inicia o código no prompt
GAME.exe
:: Deleta o executavel
Del GAME.exe

:: Cuidado para ver se ta de fato sobrescrevendo o arquivo anterior já feito, de toda forma:
:: deleta o executavel antes de gerar um novo.