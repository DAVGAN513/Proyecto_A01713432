Folder para colocar imagenes del repositorio

============COMBATIENTE============
class Combatiente {
	    -int vida 
        -int salud
        -int ataque
        -int nivel 
	    
        +porcentajeSalud() int
        +imprimeBarra() void
        +recibeAtaque(int ptosAtaque) void
	    +atacar(Combatiente objetivo)void 
        +imprimir() void
        
    }

============GUERRERO============
class Guerrero {
	    -int escudo 
        -int fuerza
	    
        +imprimir() void const override
        +recibeAtaque(int ptosAtaque) void override
	    +atacar(Combatiente objetivo)void override  
    }

============ARQUERO============
class Arquero {
	    -int precision
	    
        +imprimir() void const override
        +recibeAtaque(int ptosAtaque) void override
	    +atacar(Combatiente objetivo)void override  
    }

============MAGO============
class Mago {
	    -int mana
	    
        +imprimir() void const override
        +recibeAtaque(int ptosAtaque) void override
	    +atacar(Combatiente objetivo)void override  
    }

