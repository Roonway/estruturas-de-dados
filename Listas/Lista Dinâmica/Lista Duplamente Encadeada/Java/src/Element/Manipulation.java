package Element;

public interface Manipulation<Type> extends Comparable<Type> {
	
	public int compareToInt(Type obj);
	
	public boolean equalToInt(int value);

	int compareTo(String obj);

}
