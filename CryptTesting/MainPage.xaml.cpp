//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace CryptTesting;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void CryptTesting::MainPage::encrypt_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// take the text from the plain text field, encrypt it and display the ciphered text in the ciphertext field.
	// Use the XAML-defined TextBox controls (plainText and cipherText) exposed on this page.

	Platform::String^ plainTextValue = this->plainText->Text;
	Platform::String^ encryptedText = ref new Platform::String();

	// Simple Caesar cipher with shift of 3
	const int shift = 3;
	std::wstring result;

	for (unsigned int i = 0; i < plainTextValue->Length(); i++)
	{
		wchar_t c = plainTextValue->Data()[i];

		// Encrypt uppercase letters
		if (c >= L'A' && c <= L'Z')
		{
			c = (c - L'A' + shift) % 26 + L'A';
		}
		// Encrypt lowercase letters
		else if (c >= L'a' && c <= L'z')
		{
			c = (c - L'a' + shift) % 26 + L'a';
		}
		// Keep other characters unchanged

		result += c;
	}

	encryptedText = ref new Platform::String(result.c_str());
	this->cipherText->Text = encryptedText;

}


void CryptTesting::MainPage::decrypt_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// take the text from the cipher text field, decrypt it and display the decrypted text in the decryptedText field.
	// Use the XAML-defined TextBox controls (cipherText and decryptedText) exposed on this page.

	Platform::String^ cipherTextValue = this->cipherText->Text;
	Platform::String^ decryptedTextValue = ref new Platform::String();

	// Simple Caesar cipher with shift of 3 (reverse by shifting back 3)
	const int shift = 3;
	std::wstring result;

	for (unsigned int i = 0; i < cipherTextValue->Length(); i++)
	{
		wchar_t c = cipherTextValue->Data()[i];

		// Decrypt uppercase letters
		if (c >= L'A' && c <= L'Z')
		{
			c = (c - L'A' - shift + 26) % 26 + L'A';
		}
		// Decrypt lowercase letters
		else if (c >= L'a' && c <= L'z')
		{
			c = (c - L'a' - shift + 26) % 26 + L'a';
		}
		// Keep other characters unchanged

		result += c;
	}

	decryptedTextValue = ref new Platform::String(result.c_str());
	this->decryptedText->Text = decryptedTextValue;

}
