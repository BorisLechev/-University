package classes;

public class User implements java.io.Serializable {
    private static final long serialVersionUID = 1L;

    private String name = null;

    private String username = null;

    private String password = null;

    public User(String name, String username, String password) {
        this.setName(name);
        this.setUsername(username);
        this.setPassword(password);
    }

    public User() {

    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getUsername(){
        return username;
    }

    public void setUsername(String username){
        this.username = username;
    }

    public String getPassword(){
        return password;
    }

    public void setPassword(String password){
        this.password = password;
    }
}