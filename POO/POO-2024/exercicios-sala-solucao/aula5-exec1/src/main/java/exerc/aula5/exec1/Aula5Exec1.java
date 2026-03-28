/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package exerc.aula5.exec1;

import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author matheus
 */
public class Aula5Exec1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite uma frase: ");
        String frase = scanner.nextLine();
        HashMap<String, Boolean> palavras = new HashMap<>();

        String[] palavrasSeparadas = frase.split(" ");

        for (String palavra : palavrasSeparadas) {
            palavra = palavra.toLowerCase();

            if (!palavras.containsKey(palavra)) {
                palavras.put(palavra, true);
            }else{
                palavras.remove(palavra);
            }
        }

        System.out.println("Palavras que aparecem uma única vez: ");
        for (String palavra : palavras.keySet()) {
            System.out.println(palavra);
        }
    }
}
