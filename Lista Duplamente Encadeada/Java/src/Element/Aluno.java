package Element;

public class Aluno implements Manipulation<Aluno> {
	
	protected int registration;
	protected String name;
	
	public Aluno(int registration, String name) {
		this.registration = registration;
		this.name = name;
	}

	public int getRegistration() {
		return registration;
	}

	public void setRegistration(int registration) {
		this.registration = registration;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public int compareTo(Aluno obj) {
		
		int value = this.name.compareToIgnoreCase(obj.getName());
		
		return value;
	}
	

	@Override
	public int compareToInt(Aluno obj) {
		
		if (this.registration > obj.getRegistration()) {
			return 1;
		}
		else if (this.registration < obj.getRegistration()) {
			return -1;
		}
		else {
			return 0;
		}
	}

	@Override
	public boolean equalToInt(int value) {

		if (this.registration == value)
			return true;
		else
			return false;
		
	}

	@Override
	public int compareTo(String obj) {
		
		int value = this.name.compareToIgnoreCase(obj);
		
		return value;
	}


}
