from selenium import webdriver
import time
import unicodedata
import pandas as pd

navegador = webdriver.Edge()

tabela = pd.read_excel(r"C:\Users\farin\Downloads\commodities.xlsx")
print(tabela)



print("Pegando produtos...\n")
for i in tabela.index:
    produto = tabela.loc[i, "Produto"]
    produto = produto.replace("ó", "o").replace('ã', 'a').replace('á', 'a').replace('ç', 'c').replace('ú', 'u').replace('é', 'e')

    navegador.get(f"https://www.melhorcambio.com/{produto}-hoje")
    valor = navegador.find_element('xpath', '//*[@id="comercial"]').get_attribute("value")
    
    tabela.loc[i, "Preço Atual"] = float((valor.replace('.', '').replace(',', '.')))

    print(produto + ": " + valor)

print("Finalizado.\n")
tabela["Comprar"] = tabela["Preço Atual"] < tabela["Preço Ideal"]
print(tabela)

print("Criando Arquivo...\n")

tabela.to_excel("commodities_updated.xlsx", index=False)

print("Arquivo Criado!\n")


navegador.quit()