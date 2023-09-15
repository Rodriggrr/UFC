wget https://www.quixada.ufc.br/docente/

# pegar apenas o nome dos professores usando cut.
cat index.html | grep "<h2>" | cut -d'>' -f2 | cut -d'<' -f1 > teachers

# chat gpt me mostrou como tirar os acentos, nesse iconv, e como deixar tudo minusculo usando sed.
cat teachers | iconv -f utf-8 -t ascii//TRANSLIT | tr '[:upper:]' '[:lower:]' | sed 's/ /_/g' > teachers_formatted

# para cada linha, criar o arquivo .txt
while IFS= read -r line
do
	touch "$line.txt"
done < teachers_formatted

# remover arquivos temporarios
rm teachers
rm index.html
rm teachers_formatted


