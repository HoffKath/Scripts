package posicoes; //empacota a pasta posicoes
import java.lang.Math; //importa a biblioteca Math para poder fazer raiz
// Parte 2:

public class PosicaoMapa4x4 {
  private int x; //variavel de posição
  private int y; //variavel de posição
  private static int numPosicoesOcupadas; 
  
  public PosicaoMapa4x4(){ //inicializa um objeto
    reset();
    this.x = 0;
    this.y = 0;
  }
  
  public PosicaoMapa4x4(int x, int y){ //dá posição ao objeto
    this.x = x;
    this.y = y;
  }
  
  public boolean setX(int x){ //determina se posição x é aplicavel ap objeto, aplica e retorna true, senão false
    if(x >= 0 && x <= 3){
      this.x = x;
      return true;
    }else{
      return false;
    }
  }
  
  public boolean setY(int y){ //determina se posição y é aplicavel ap objeto, aplica e retorna true, senão false
    if(y >= 0 && y <= 3){
      this.y = y;
      return true;
    }else{
      return false;
    }
  }
  
  public int getX(){ //retorna a posição x do objeto
    return x;
  }
  
  public int getY(){ //retorna a posição y do objeto
    return y;
  }
  
  public static int getNumPosicoesOcupadas(){ //retorna o número de posições ocupadas / numero de droes
    return numPosicoesOcupadas;
  }
  
  public PosicaoMapa4x4 copy(){ //copia um objeto para outro
    int novoX = this.x;
    int novoY = this.y;
    PosicaoMapa4x4 novoObjeto = new PosicaoMapa4x4(novoX, novoY);
    return novoObjeto;
    
  }
  
  public void imprime(){ //imprime coordenadas de um objeto
    System.out.printf("(%d,%d) \n", this.x, this.y);
  }
  
  public double distancia(PosicaoMapa4x4 p){ //determina a distancia entre dois objetos
    double distancia = Math.sqrt((p.x - this.x)*(p.x - this.x) + (p.y - this.y)*(p.y - this.y));
    return distancia;
  }
  
  private void reset(){ //reseta as posiçõesde um objeto
    this.x = 0;
    this.y = 0;
  }
  
  public static boolean  estaoMesmaPosição(PosicaoMapa4x4 p1,PosicaoMapa4x4 p2){ //verifica se dois objetos estão na mesma posição
    boolean retorno = false;
    
    if(p1.x == p2.x){
      if(p1.y == p2.y){
        retorno = true;
      }else{
        retorno = false;
      }
    }
    return retorno;
  }
  
  
}
