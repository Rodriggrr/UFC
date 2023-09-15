# cat compras.txt | grep -Eo "\b[0-9].*" | xargs | sed "s/ / + /g" | bc

# outro metodo

sum=$(cat compras.txt | grep -Eo "\b[0-9].*" | xargs | sed "s/ / + /g")
expr $(echo $sum)
