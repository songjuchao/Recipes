import java.io.IOException;
import java.io.OutputStream;

/**
 * Created by Administrator on 2017/8/22.
 */
public class Chargen {
    public static void generateCharacters(OutputStream out) throws IOException {
        int firstPrintableCharacter = 33;
        int numberOfPrintableCharacters = 94;
        int numberOfCharacterPerLine = 72;

        int start = firstPrintableCharacter;
        while(true) {
            for (int i = start; i < start + numberOfCharacterPerLine; i++) {
                out.write((i-firstPrintableCharacter)%numberOfPrintableCharacters + firstPrintableCharacter);
            }
            out.write('\r');
            out.write('\n');
            start = ((start+1) - firstPrintableCharacter)%numberOfPrintableCharacters + firstPrintableCharacter;
        }
    }

    public static void generateCharactersTotal(OutputStream out) throws IOException {
        int firstPrintableCharacter = 33;
        int numberOfPrintableCharacters = 94;
        int numberOfCharacterPerLine = 72;

        int start = firstPrintableCharacter;
        byte[] line= new byte[numberOfCharacterPerLine+2];
        while(true) {
            for (int i = start; i < start+numberOfCharacterPerLine; i++) {
                line[i-start] = (byte)((i-firstPrintableCharacter)%numberOfPrintableCharacters + firstPrintableCharacter);
            }
            line[72] = '\r';
            line[73] = '\n';
            out.write(line);
            start = ((start+1) - firstPrintableCharacter)%numberOfPrintableCharacters + firstPrintableCharacter;
        }
    }

    public static void main(String[] args) {
        try {
            generateCharacters(System.out);
        } catch(IOException exception) {
            System.out.println();
        }
    }
}
