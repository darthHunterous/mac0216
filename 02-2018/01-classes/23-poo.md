# Aula 23 - Java, Objetos e Classes

### Objetos
* Construção de uma abstração para melhor modelar informações e dados tratados pelo programa
* Centro da programação não reside mais na sequência de operações (programação imperativa)
* Vantagens como reutilização de código, extensibilidade e independência de implementação
* **Objeto:** entidade representada no computador
    * Tudo é objeto. Há vários tipos ou classes de objetos. Qualquer elemento do programa, incluindo ele mesmo, é representado como objeto
    * Programa: coleção de objetos interagindo
    * Um objeto pode ser composto por outros
    * Todo objeto tem tipo, sendo instância de uma classe
    * Classes podem conter subclasses
    * Tipo é conjunto, subtipo é restrição desse conjunto
    * Objetos de mesma classe reagem da mesma maneira
* **Descrição de Objeto:** por três propriedades
    * **Estado:** conjunto de variáveis
    * **Comportamento:** descrito por funções (métodos)
    * **Identidade:** instância do objeto, um endereço na memória
* **Classe:** representad por uma *implementação*
* Conjunto de variáveis descreve o estado e conjunto de funções o comportamento

### Encapsulamento
* Para que um objeto A atue sobre um B, não é necessário conhecer a implementação de B, apenas como chamar métodos de B que permitam interação
* Implementador de A não deve fazer suposições sobre a implementação de B
* Toda classe pode esconder a implementação e apresentar apenas a interface

### Herança
* Uma classe pode ser uma restrição sobre uma classe maior, ou seja, um caso mais específico
    * Sendo assim, não é necessário reconstruir a implementação, bastando estender a implementação já existente da classe maior com restrição de tipo
* Se a classe B deriva de A, usa a mesma interface, incluindo algumas coisas
    * Em qualquer ponto em que se usa um objeto A, pode-se usar um objeto B sem a necessidade de reprogramar
* Duas formas de herança: especializando (trocando métodos por mais específicos) ou estendendo (adicionando campos e métodos)

### Polimorfismo
* Funções que manipulam um objeto podem precisar atuar diferentemente sobre objetos subclasses ou classes similares
    * A chamada é escrita igual, mas o código executado pode ser diferente
* Busca em tempo de execução (late binding), pois só é possível descobrir a função chamada em tempo de execução
* Duas funções podem ter a mesma funcionalidade com implementações diferentes, de acordo com o tipo dos argumentos

### Diretrizes para Implementação de Classes
* **Agrupamento**: classes podem ser agrupadas em pacotes, com elementos relacionados entre si, porém implementados com certa independência
    * Certas implementações podem precisar de classes auxiliares
* **Construtores:** método especial para criar uma nova instância do objeto, alocando memória para objeto e o inicializando
    * Polimorfismo usado com frequência quando há mais de uma forma de se criar um objeto
* **Proteção e Escopo:** garantir encapsulamento da implementação, coibindo acesso à estrutura interna
    * Métodos e variáveis (campos) com 3 níveis de encapsulamento
        * **public:** aberto, qualquer método de qualquer classe pode ter acesso ao campo
        * **protected:** para acessar este campo, o método precisa pertencer a uma subclasse ou a outra classe do pacote
        * **private:** acesso permitido apenas a métodos da mesma classe, excluindo subclasses
* **Encapsulamento de classe:** dois níveis
    * **public:** pode ser instanciada ou estendida por qualquer outra classe
    * **Amigável:** só pode ser usada dentro do pacote onde foi definida
* **Classe Abstrata**: classe que especifica métodos que só serão definidos em subclasse
    * Não é possível instanciar classes abstratas
* **Classes Finais:** não permitem derivação
    * Método final se ele não permite especialização (ser sobrescrito)
* Variável final, é na verdade uma constane
* Método abstrato não tem corpo
* **Váriaveis de Classe:** variáveis na classe, únicas para todas instâncias
    * Por exemplo, manter contagem de objetos já criados

### Java
* Tudo em Java faz parte de algum objeto, sendo todas classes derivadas implicitamente da classe especial `Object`
    * Exceções, para eficiência são os tipos fundamentais

### Java - Classes
* Sintaxe de declaração
    * `[modificadores-de-classe] class nome [extends nome-da-superclasse] [implements lista-de-interfaces] { corpo }`
* **Modificadores:**
    * **abstract:** indica que a classe tem métodos virtuais (abstratos)
    * **final:** classe não pode ter subclasses
    * **public:** apenas uma classe pública por arquivo
* Métodos **abstract** não tem corpo, sendo definidos em alguma subclasse
    * Apenas classes abstract podem ter métodos abstract
* **Construtor:** método com o mesmo nome da classe, sem tipo e público
    * Chamado automaticamente ao instancia a classe

### Java - Entrada e Saída
* Saída padrão através de um objeto especial da classe `java.io.PrintStream`, o `System.out`
    * Objeto `static`, com métodos `print()`, `println()` e `flush()`
* Entrada padrão através de `java.io.InputStreamReader` e `java.io.BufferedReader`

### Java - Pacotes
* Define-se pacotes com a palavra reservada `package`
* No ínicio de `MyClass.java` pode-se usar:
    * `package mypackage;`
    * `public class MyClass {`
    * MyClass pertencerá ao pacote `mypackage`
* A diretiva `package` deve ser a primeira do arquivo
* Um arquivo `.java` só pode ter uma classe `public`, podendo haver vários arquivos no mesmo pacote: todos precisam usar o mesmo comando `package` e estar no mesmo diretório
* **Instanciar classe em outro pacote**
    * `mypackage.MyClass m = new mypackage.MyClass();`
    * ou
    * ```java
      import mypackage.*;
      // ...
      MyClass m = new MyClass();
      ```

### Java - Localização de Classes
* Na compilação, Java coloca cada classe em um arquivo `.class` diferente
* Pacotes colocados em diretórios, podendo haver subdiretórios para melhor organização
* Se as classes de um pacote estão no subdiretório como `diretorio/subdir1/subdir2` podemos importar as classes deste pacote usando:
    * `import diretorio.subdir1.subdir2.*`
* O diretório `diretorio` deve estar incluso na variável de ambiente `CLASSPATH`
* Para importar apenas uma das classes de tal pacote:
    * `import diretorio.subdir1.subdir2.Classe`

### Java - Herança
* Classe Progressão Numérica
    ```java
    public class Progression {
        protected long first; // valor inicial
        protected long cur; // valor atual

        Progression() { // construtor
            cur = 0;
            first = 0;
        }
        /* Reinicializa com o valor inicial
        *  @return Valor inicial
        */
    }
* Classe de Progressão Aritmética
    ```java
    class Aritmetica extends Progression {
        protected long inc;

        Aritmetica() {
            this(1);
        }
        Aritmetica(long incr) {
            inc = incr;
        }
        protected long proximoValor() {
            cur += inc;
            return cur;
        }
    }
* Classe Progressão Geométrica
    ```java
    class Geometrica extends Progression {
        protected long base;

        Geometrica() {
            this(2);
        }
        Geometrica(long inc) {
            first = incr;
            base = incr;
        }
        protected long proximoValor() {
            cur *= base;
            return cur;
        }
    }
    ```
* Classe Progressão de Fibonacci
    ```java
    class Fibonacci extendes Progression {
        protected long prev;

        Fibonacci() {
            this(0,1);
        }
        Fibonacci(long v1, long v2) {
            first = v1;
            prev = v2-v1;
        }

        protected long proximoValor() {
            long temp = prev;
            prev = cur;
            cur += temp;

            return cur;
        }
    }
    ```
* Classe para testar progressões
    ```java
    public class Tester {
        public static void main(String[] args) {
            System.out.println("Testador de progressões");
            Progression vp[] = {
                new Progression(),
                new Aritmetica(5),
                new Geometrica(3),
                new Fibonacci(1,2)
            };
            for (int i = 0; i < vp.length; i++)
                vp[i].print(6);
        }
    }
    ```

### Java - Interfaces
* Para criar objeto com característica de dois tipos diferentes faria-se necessária herança múltipla, porém, ela tem inconvenientes como herdar implementações do mesmo método ou ser derivada mais de uma vez da mesma base
    * Ademais, campos ou métodos de um ancestral comum pode ser modificados indiretamente por métodos diferentes
* **Interfaces:** declara métodos que devem ser implementados em outras classe, como os virtuais
    * Instância de uma classe C que implementa métodos de interface I podem ser usados como objetos de tipo I, mesmo tal tipo não sendo completo
    * Evita problemas de herança múltipla mas permitindo que os objetos sejam considerado como de mais de um tipo

### Java - Contêineres
* Estrutura de dados que armazena coleção de objetos
    * Arrays, pilhas, filas, coleções
* **Arrays**: tamanho fixo na criação, não podem ser modificados dinamicamente
    * Tipo dos elementos de array é conhecido, podendo ser verificado, ao contrário dos outros contâineres, de tipo `Object`
    * Índice fora dos limites do array gera erro de execução
    * Comporta-sem como objeto normal, tem campo especial **length**
    * Na criação, é inicializado com referências para *null*
        * Elementos devem ser criados ou declarados explicitamente, a menos que de um tipo básico
    * **Classe Arrays:** em `java.utils`, contendo métodos `static`
        * `fill(array, val)`: preenche array com o valor
        * `sort(array)`: ordena
        * `equals(array1, array2)`: verifica igualdade
        * `binarySearch(array, valor)`: busca o valor
        * `asList(array)`: retorna o array como lista da classe `List` de `java.utils`
        * Há também o método `static` do sistema, `System.arraycopy()`
* **Collection:** `List` ou `Set`
    * Listas são coleções ordenadas e conjuntos coleções sem repetições
* **Maps:** vetores associativos da forma chave-valor
    * Chave e valor podem ser qualquer objeto, até mesmo `Maps`
* **Problema com contâineres:** tipo original do elmeento se perde
    * Ao ser colocado no container, o objeto é convertido para tipo `Object`, ao se recuperar o objeto, faz-se necessária conversão para tipo original
* Em Java não existem tipos parametrizados (**templates**)