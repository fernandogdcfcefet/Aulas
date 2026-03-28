/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package exerc.heranca;
import veiculos.veiculo;
import veiculos.moto;
import java.util.*;
/**
 *
 * @author matheus
 */
public class Heranca {

    public static void main(String[] args) {

        moto m1 = new moto();
        m1.setNumPassageiros(2);
        m1.setLitrosTanqueCombustivel(15.5);
        m1.setPlaca("OWW-9911");
        System.out.println(m1.litrosTanqueCombustivel);
        System.out.println(m1.getNumPassageiros());
        m1.litrosTanqueCombustivel = 13;
        System.out.println("Main: Placa: " + m1.getPlaca());
        m1.imprimePlaca();
        ArrayList<veiculo> lista = new ArrayList<>();
        lista.add(m1);
        System.out.println("Imprimindo elemento da lista: placa = " + lista.get(0).getPlaca() + " numero de litros: " + lista.get(0).litrosTanqueCombustivel);
        
    }
}
