/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package exerc.aula5exerc2;
import java.util.*;
/**
 *
 * @author matheus
 */
public class Aula5Exerc2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        HashMap<Integer, String> diasDoMes = new HashMap<>();
        diasDoMes.put(1, "Janeiro");
        diasDoMes.put(2, "Fevereiro");
        diasDoMes.put(3, "Março");
        diasDoMes.put(4, "Abril");
        diasDoMes.put(5, "Maio");
        diasDoMes.put(6, "Junho");
        diasDoMes.put(7, "Julho");
        diasDoMes.put(8, "Agosto");
        diasDoMes.put(9, "Setembro");
        diasDoMes.put(10, "Outubro");
        diasDoMes.put(11, "Novembro");
        diasDoMes.put(12, "Dezembro");
        
        int dia = 0;
        
        do{
            System.out.println("Digite o dia do mês (1 a 12): ");
            dia = scanner.nextInt();
            
        }while(dia <= 0 || dia > 12);

        // Obtém o nome do mês por extenso
        String nomeDoMes = diasDoMes.get(dia);

            System.out.println("O dia " + dia + " corresponde ao mês de " + nomeDoMes);
    }
}
