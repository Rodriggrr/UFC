cat index.html | grep 'Obrigatória' -B2 | grep -E 'td>......[0-9]' | cut -d '-' -f2 | iconv -f utf-8 -t ascii//TRANSLIT | sed 's/,//g' | sed 's/ /_/g' | sed 's/^_//g' | sed 's/_$//g' | tr '[:upper:]' '[:lower:]' | sed 's/\//_/g'  > disciplinas

while IFS= read -r line
do
	touch "$line.txt"
done < disciplinas
