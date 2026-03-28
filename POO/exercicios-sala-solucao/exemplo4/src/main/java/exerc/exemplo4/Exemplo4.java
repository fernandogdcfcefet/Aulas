/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package exerc.exemplo4;

import java.util.*;
/**
 *
 * @author matheus
 */
public class Exemplo4 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
         
        List<Integer> vetorInt = new ArrayList<>();
        vetorInt.add(2);
        vetorInt.add(5);
        vetorInt.add(9);
        vetorInt.remove(2);
        
        System.out.println("Valores inteiros inseridos: ");
        for (Integer valor : vetorInt) {
            System.out.println(valor);
        }
        // Cria um ArrayList para armazenar valores reais
        ArrayList<Double> valoresReais = new ArrayList<>();

        // Lê a quantidade de valores a serem inseridos
        System.out.println("Digite a quantidade de valores a serem inseridos: ");
        int quantidade = scanner.nextInt();

        for (int i = 0; i < quantidade; i++) {
            System.out.printf("Digite o %dº valor: ", i + 1);
            double valor = scanner.nextDouble();
            valoresReais.add(valor);
        }

        System.out.println("Valores reais inseridos: ");
        for (Double valor : valoresReais) {
            System.out.println(valor);
        }
        
        for(int i = 0; i < valoresReais.size(); i++){
            if(valoresReais.get(i) < 0){
                valoresReais.remove(i);
            }
        }
        
        System.out.println("Valores reais positivos: ");
        for (Double valor : valoresReais) {
            System.out.println(valor);
        }
        
    }
}
