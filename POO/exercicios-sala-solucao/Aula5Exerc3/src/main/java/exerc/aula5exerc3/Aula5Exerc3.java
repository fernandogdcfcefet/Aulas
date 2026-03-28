/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package exerc.aula5exerc3;
import java.util.*;
/**
 *
 * @author matheus
 */
public class Aula5Exerc3 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê a frase do usuário
        System.out.println("Digite uma frase: ");
        String frase = scanner.nextLine();

        // Cria um HashMap para armazenar a contagem de ocorrências de cada palavra
        HashMap<String, Integer> contagemDeOcorrencias = new HashMap<>();

        // Divide a frase em palavras
        String[] palavrasSeparadas = frase.split(" ");

        // Percorre cada palavra
        for (String palavra : palavrasSeparadas) {
            // Converte a palavra para minúsculas
            palavra = palavra.toLowerCase();

            // Obtém a contagem atual da palavra
            Integer contagemAtual = contagemDeOcorrencias.get(palavra);

            // Se a palavra não estiver no HashMap, inicializa a contagem com 1
            if (contagemAtual == null) {
                contagemDeOcorrencias.put(palavra, 1);
            } else {
                // Incrementa a contagem da palavra
                contagemDeOcorrencias.put(palavra, contagemAtual + 1);
            }
        }

        // Imprime a contagem de ocorrências de cada palavra
        System.out.println("Contagem de ocorrências de palavras: ");
        for (String palavra : contagemDeOcorrencias.keySet()) {
            Integer contagem = contagemDeOcorrencias.get(palavra);
            System.out.println(palavra + ": " + contagem);
        }
    }
}
