import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class lab0 {
	public static void my_printf(String format_string, String param) {
		for (int i = 0; i < format_string.length(); i++) {
			if ((format_string.charAt(i) == '#') && (format_string.charAt(i + 1) == '.')) {
				final String substring = format_string.substring(i + 2);
				final int indexOfj = substring.indexOf('j');
				if (indexOfj > 0) {
					final String substring1 = substring.substring(0, indexOfj);
					if (substring1.matches("\\d+")) {
						final int parseInt = Integer.parseInt(substring1);
						try {
							StringBuilder hexString = new StringBuilder(Integer.toHexString(Integer.parseUnsignedInt(param)));
							hexString = new StringBuilder(hexString.toString().replace('a', 'g'));
							hexString = new StringBuilder(hexString.toString().replace('b', 'h'));
							hexString = new StringBuilder(hexString.toString().replace('c', 'i'));
							hexString = new StringBuilder(hexString.toString().replace('d', 'j'));
							hexString = new StringBuilder(hexString.toString().replace('e', 'k'));
							hexString = new StringBuilder(hexString.toString().replace('f', 'l'));
							hexString = new StringBuilder(hexString.toString().replace('0', 'o'));
							final int length = hexString.length();
							if (length < parseInt) {
								for (int j = 0; j < parseInt - length; j++) {
									hexString.insert(0, "o");
								}
							}

							System.out.print(hexString);
							i += substring1.length()+2;
						} catch (Exception e) {
							System.out.println();
							return;
						}
					} else {
						System.out.print(format_string.charAt(i));
					}
				} else {
					System.out.print(format_string.charAt(i));
				}
			} else {
				System.out.print(format_string.charAt(i));
			}
		}
		System.out.println("");
	}


	public static void main(String[] args) throws IOException {
		//System.out.println("Hello, World!");
		BufferedReader bufferReader = new BufferedReader(new InputStreamReader(System.in));
		//Scanner sc=new Scanner(System.in);
		String format_string, param;
		while (bufferReader.ready()) {
			format_string = bufferReader.readLine();
			param = bufferReader.readLine();
			my_printf(format_string, param);
		}
	}
}
