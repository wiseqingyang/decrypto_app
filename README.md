
- 基于 Qt5.7.1 + Visual Studio 2013 编写的加解密应用

- 加密方法用的是 [Qt-AES](https://github.com/bricke/Qt-AES)


- 加密文件或文件夹时，会在同目录下生成 `en_`+`原文件（夹）名字` 的文件或文件夹，

- 解密文件或文件夹时，会在同目录下生成 `de_`+`原文件（夹）名字` 的文件或文件夹，

- 解密文件时，为安全起见，如果文件长度不是 16 的整数倍，则认为不是加密后的文件，不予解密。

- 密钥在 `TestUtils.cpp` 中修改，只能是16位。

这个项目是用来将 Android 应用中加密的文件导出到 Windows 后解密。

Java加密代码如下，可以与 Windows 互通

```Java
private static final String IV_STRING = "1234567891234567";

public static byte[] encryptDatas(String key, byte[] byteContent) {
    byte[] encryptedBytes = null;
    try {
    	byte[] enCodeFormat = key.getBytes();
    	SecretKeySpec secretKeySpec = new SecretKeySpec(enCodeFormat, "AES");
    	byte[] initParam = IV_STRING.getBytes();
    	// 用于产生密文的第一个block，以使最终生成的密文产生差异（明文相同的情况下），
    	// 使密码攻击变得更为困难，除此之外IvParameterSpec并无其它用途。
    	// 为了方便也可以动态跟随key生成new IvParameterSpec(key.getBytes("utf-8"))
    	Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
    	IvParameterSpec ivParameterSpec = new IvParameterSpec(initParam);
    	cipher.init(Cipher.ENCRYPT_MODE, secretKeySpec, ivParameterSpec);
    	encryptedBytes = cipher.doFinal(byteContent);
    } catch (Exception e) {
    	e.printStackTrace();
    }
    return encryptedBytes;
}
```

- 小技巧，如果在做多语言相互加密解密时，因为加密后的密文是人类不可读的，所以用 base64 转换后的字符串比较是各个语言加密后的密文一致。 


