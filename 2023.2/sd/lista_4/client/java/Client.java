package client.java;

class Client {
    public static void main(String[] args) {
        Proxy calc = new Proxy("127.0.0.1", 49100);

        System.out.println(calc.add(4, 2));
        System.out.println(calc.sub(4, 2));
        System.out.println(calc.mul(4, 2));
        System.out.println(calc.div(4, 2));
    }
}