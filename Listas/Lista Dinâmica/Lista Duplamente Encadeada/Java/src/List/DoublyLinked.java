package List;

import Element.*;

public class DoublyLinked <Type extends Manipulation<Type>>{

	private class Element{
		Type type;
		Element anterior, proximo;
	}
	
	private Element firstElement = null;
	
	public int getSize() {
		if(firstElement == null) {
			return 0;
		}
		
		int amount = 0;
		Element no = firstElement;
		
		while(no != null) {
			amount++;
			no = no.proximo;
		}

		return amount;
	}
	
	public boolean isEmpty() {
		if(firstElement == null) {
			return true;
		}
		return false;
	}
	
	public boolean actionInsert(Type type) {
		Element no = new Element();
		
		no.type = type;
		no.proximo = null;
		
		if(firstElement == null) {
			no.anterior = null;
			firstElement = no;
			
			return true;
		} else {
			Element aux = firstElement;
			
			while (aux != null && aux.type.compareTo(type) > 0) {
				
				if(aux.type.compareTo(type) == 0) {
					
					int value = aux.type.compareToInt(type);
					
					if(value > 0) {
						no.anterior =  aux.anterior;
						no.proximo = aux;
						
						aux.proximo.anterior = no;
						aux.proximo = no;
						
						return true;
					} 
					else if (value < 0) {
						no.anterior =  aux;
						no.proximo = aux.proximo;
						
						aux.anterior.proximo = no;
						aux.anterior = no;
						
						return true;
					}
					else {
						return false;
					}
				}
				aux = aux.proximo;
			}
			
			if(aux == null) {
				
				no.anterior = null;
				no.proximo = firstElement;
				
				firstElement.anterior = no;
				firstElement = no;
			} else {
				
				no.anterior =  aux;
				no.proximo = aux.proximo;
				
				aux.proximo.anterior = no;
				aux.proximo = no;
			}
			
			return true;
		}
	}	
	
	public boolean actionRemover(int registration) {
		if(isEmpty()) {
			return false;
		}
		
		Element no = firstElement;
		
		while(no != null && no.type.equalToInt(registration)) {
			no = no.proximo;
		}
		
		if(no == null) {
			return false;
		}
		
		if(no.anterior == null) {
			firstElement = no.proximo;
		} else {
			no.anterior.proximo = no.proximo;
		}
		
		if(no.proximo != null) {
			no.proximo.anterior = no.anterior;
		}
		return true;
	}
	
	public Type getElementByName(String str) {
		if(isEmpty()) {
			return null;
		}
		
		Element aux = firstElement;
		
		while(aux != null && aux.type.compareTo(str) == 0){
			aux = aux.proximo;
		}
		
		if(aux == null) {
			return null;
		}
		
		return aux.type;
	}
	
	public Type getElementByRegistration(int registration) {
		if(isEmpty()) {
			return null;
		}
		
		Element aux = firstElement;
		
		while(aux != null && aux.type.equalToInt(registration)){
			aux = aux.proximo;
		}
		
		if(aux == null) {
			return null;
		}
		
		return aux.type;
	}
	
}

