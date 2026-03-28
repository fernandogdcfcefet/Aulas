/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package veiculos;

/**
 *
 * @author matheus
 */
public class veiculo {
    protected String placa;
    protected double velocidade;
    protected int numRodas;
    protected double litrosTanqueCombustivel;
    private int numPassageiros;

    public int getNumPassageiros() {
        return numPassageiros;
    }

    public void setNumPassageiros(int numPassageiros) {
        this.numPassageiros = numPassageiros;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public double getVelocidade() {
        return velocidade;
    }

    public void setVelocidade(double velocidade) {
        this.velocidade = velocidade;
    }

    public int getNumRodas() {
        return numRodas;
    }

    public void setNumRodas(int numRodas) {
        this.numRodas = numRodas;
    }

    public double getLitrosTanqueCombustivel() {
        return litrosTanqueCombustivel;
    }

    public void setLitrosTanqueCombustivel(double litrosTanqueCombustivel) {
        this.litrosTanqueCombustivel = litrosTanqueCombustivel;
    }
    
    public void imprimePlaca(){
        System.out.println("placa: " + this.placa);
    }
    
}
