/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package exerc.tessdr;

/**
 *
 * @author matheus
 */
public class Tessdr {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        String res = "";
        String s1 = "aaaaaa";
        String s2 = "bbbbbb";
        int i = 0;
        while(i < s1.length()){
            res = res + s1.charAt(i);
            
            res = res + s2.charAt(i);
            i++;
        }
        System.out.println(res);
    }
}
