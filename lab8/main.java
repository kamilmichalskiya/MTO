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
							String hexString = Integer.toHexString(Integer.parseUnsignedInt(param));
							hexString = hexString.replace('a', 'g');
							hexString = hexString.replace('b', 'h');
							hexString = hexString.replace('c', 'i');
							hexString = hexString.replace('d', 'j');
							hexString = hexString.replace('e', 'k');
							hexString = hexString.replace('f', 'l');
							hexString = hexString.replace('0', 'o');
							if (hexString.length() < parseInt) {
								for (int j = 0; j <= parseInt - hexString.length(); j++) {
									hexString = "o" + hexString;
								}
							}

							System.out.print(hexString);
							i += substring1.length()+1;
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
				i++;
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
