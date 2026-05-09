const math = require('math-js');
const prompt = requiere('prompt-sync')();
class Personaje{
    constructor(nombre, vida, defensa, ataque){
        this.nombre = nombre;
        this.vida = Math.min(vida,100);
        this.defensa = Math.min(defensa,17);
        this.ataque = Math.min(ataque,25);
    }
    static anonymous(){
        return new Personaje("0",0,0,0);
    }
    setNombre(nombre){this.nombre=nombre};
    setVida(vida){this.vida=vida};
    setDefensa(defensa){this.defensa=defensa};
    setAtaque(ataque){this.ataque=ataque};
    atacar(objetivo){
        if(objetivo.defensa > this.ataque){
            console.log("Ataque fallido!")
            return
        }
        else{
            objetivo.recibirDanio(this.ataque - objetivo.defensa + 1);
            console.log(`Felicitaciones, has asestado un ataque de ${this.ataque - objetivo.defensa + 1} hitpoints a ${objetivo.nombre}`)
        }
    }
    recibirDanio(cantidad){
        this.vida -= cantidad;
        console.log(`Has recibido un ataque de ${cantidad} hitpoints`)
    }
    estaVivo(){
        return this.vida > 0;
    }
    mostrarEstado(){
        if(this.estaVivo()){
        console.log(`Bienvenido, ${this.nombre}. Este es su estado ahora mismo.`);
        console.log(`Vida: ${this.vida} \nDanio:${this.ataque}\nDefensa:${this.defensa}`)
        }
        else{
            console.log("Usted esta muerto, no haga preguntas de ultratumba!");
        }
    }
}

class Guerrero extends Personaje{
    constructor(nombre, vida, defensa, ataque){
        super(nombre, vida, Math.min(defensa+5,20), ataque);
    }
    golpeFuerte(objetivo){
        if(objetivo.defensa > this.ataque+3){
            console.log("Ataque fallido!")
            return
        }
        else{
            objetivo.recibirDanio(this.ataque+3 - objetivo.defensa + 1);
            console.log(`Felicitaciones ${this.nombre}, has asestado un ataque de ${this.ataque - objetivo.defensa + 1} hitpoints`)
        }
    }
}

class Mago extends Personaje{
    constructor(nombre, vida, defensa, ataque, mana){
        super(nombre, vida, defensa, ataque);
        this.mana = mana;
    }
    tieneManaSuficiente(manaNecesario){
        return this.mana >= manaNecesario;
    }
    lanzarHechizo(objetivo){
        const costo = 20;
        if (this.tieneManaSuficiente(costo)){
        this.ataque *= 1.5;
        this.atacar(objetivo);
        this.ataque /= 1.5;
        this.mana -= costo}
        else{
            console.log("Usted no tiene maná suficente");
        }
    }
}

class Arquero extends Personaje{
    constructor(nombre, vida, defensa, ataque, probaCritico){
        super(nombre, vida, defensa, ataque);
        this.probaCritico = probaCritico;
    }
    tuvoExito(){
        let numeroAleatorio = Math.random();
        return Math.random() > this.probaCritico;
    }
    golpeCritico(objetivo){
        if (this.tuvoExito()){
            this.ataque *= 2;
            this.atacar(objetivo);
            this.ataque /= 2;
        }
        else{
            console.log(`Has perdido tu turno, ${this.nombre}! No has asestado el ataque.`);
        }
    }
}

function menu(){
    console.log("-" * 30);
    console.log("1- Crear personaje");
    console.log("2- Tomar un duelo con uno de nuestros personajes");
    console.log("3- Modificar nombre");
    console.log("0 - Salir")
    console.log("-" * 30);
}

function menu2(){
    console.log("-" * 30);
    console.log("1- Arcano el Balcano");
    console.log("2- Los Lego");
    console.log("3- Sportacus Espartano");
    console.log("0 - Salir")
    console.log("-" * 30);
}

opc = "1"
while(opc != '0'){
    menu()
    opc = prompt("Ingrese una opcion").trim();
    switch(opc){
        case '1':{
            let maxTreshold = 185;
            console.log("Bienvenido al menu!")
            nombre = prompt("Elija su nombre: ");
            
        }
        case '2':
            {

            }
        case '3':
            {

            }
        case '0':
            {
                console.log("Gracias por jugar! Deja de stalkearme el GitHub, chinchulin");
            }
        default:
            console.log("Por favor, ingrese una opcion entre el 0 y el 3")
    }
}
