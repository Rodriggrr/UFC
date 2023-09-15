while IFS= read -r line
do
	cd ~/OneDrive/Ubuntu/atividades/atividade02/historico/$line
	ln -sf ../../disciplinas/$line.txt programa
done < pastas
