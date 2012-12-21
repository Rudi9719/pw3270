/*
 * "Software pw3270, desenvolvido com base nos códigos fontes do WC3270  e X3270
 * (Paul Mattes Paul.Mattes@usa.net), de emulação de terminal 3270 para acesso a
 * aplicativos mainframe. Registro no INPI sob o nome G3270. Registro no INPI sob o nome G3270.
 *
 * Copyright (C) <2008> <Banco do Brasil S.A.>
 *
 * Este programa é software livre. Você pode redistribuí-lo e/ou modificá-lo sob
 * os termos da GPL v.2 - Licença Pública Geral  GNU,  conforme  publicado  pela
 * Free Software Foundation.
 *
 * Este programa é distribuído na expectativa de  ser  útil,  mas  SEM  QUALQUER
 * GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou  de  ADEQUAÇÃO
 * A QUALQUER PROPÓSITO EM PARTICULAR. Consulte a Licença Pública Geral GNU para
 * obter mais detalhes.
 *
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este
 * programa; se não, escreva para a Free Software Foundation, Inc., 51 Franklin
 * St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Este programa está nomeado como options.c e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 * licinio@bb.com.br		(Licínio Luis Branco)
 * kraucer@bb.com.br		(Kraucer Fernandes Mazuco)
 *
 */

#include "globals.h"

/*---[ Globals ]--------------------------------------------------------------------------------------------------------------*/


/*---[ Statics ]--------------------------------------------------------------------------------------------------------------*/

 static const const LIB3270_OPTION_ENTRY options[LIB3270_OPTION_COUNT+1] =
 {
	{
		LIB3270_OPTION_KYBD_AS400,
		"as400",
		N_( "Host is AS/400" ),
		NULL
	},

	{
		LIB3270_OPTION_TSO,
		"tso",
		N_( "Host is TSO" ),
		NULL
	},

	{
		0,
		NULL,
		NULL,
		NULL
	}

 };



/*---[ Implement ]------------------------------------------------------------------------------------------------------------*/

LIB3270_EXPORT LIB3270_OPTION lib3270_get_options(H3270 *hSession)
{
	CHECK_SESSION_HANDLE(hSession);
	return hSession->options;
}

LIB3270_EXPORT void lib3270_set_options(H3270 *hSession, LIB3270_OPTION opt)
{
	CHECK_SESSION_HANDLE(hSession);
	hSession->options = opt;
}

LIB3270_EXPORT int lib3270_set_color_type(H3270 *hSession, unsigned short colortype)
{
	CHECK_SESSION_HANDLE(hSession);

	switch(colortype)
	{
	case 0:
	case 16:
		hSession->colors 	= 16;
		hSession->mono		= 0;
		break;

	case 8:
		hSession->colors	= 8;
		hSession->mono		= 0;
		break;

	case 2:
		hSession->colors 	= 16;
		hSession->mono		= 1;
		break;

	default:
		return EINVAL;
	}


	return 0;
}


LIB3270_EXPORT const LIB3270_OPTION_ENTRY * lib3270_get_option_list(void)
{
	return options;
}
