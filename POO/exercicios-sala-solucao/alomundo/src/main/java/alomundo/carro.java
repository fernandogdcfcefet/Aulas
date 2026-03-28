/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package alomundo;

/**
 *
 * @author matheus
 */
public class carro {

    public void setVelocidade(float velocidade) {
        this.velocidade = velocidade;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public float getVelocidade() {
        return velocidade;
    }

    public int getAno() {
        return ano;
    }
    private float velocidade;
    private int ano;
    
    public carro(float velocidade, int ano){
        this.velocidade = velocidade;
        this.ano = ano;
    }
    
}
