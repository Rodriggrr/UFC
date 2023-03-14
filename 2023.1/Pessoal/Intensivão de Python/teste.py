import pyautogui as pag
import pandas    as pd
import time

# time.sleep(5)
# print(pag.position())

# pag.press("win")
# pag.write("edge")
# time.sleep(1)
# pag.press("enter")
# time.sleep(1)
# pag.write("rodriggrr.github.io")
# pag.press("enter")
# time.sleep(1)
# pag.click(x=517, y=192)
# pag.write("Rodrigo")
tabela = pd.read_csv(r"C:\Users\farin\Downloads\Compras.csv", sep=";")
print(tabela)

total_gasto = tabela["ValorFinal"].sum()
quantidade = tabela["Quantidade"].sum()
preco_medio= total_gasto/quantidade

print(total_gasto)
print(quantidade)
print(preco_medio)