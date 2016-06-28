<?php

/* vim: set expandtab tabstop=4 shiftwidth=4 softtabstop=4: */

/**
 * This file is part of A2Billing (http://www.a2billing.net/)
 *
 * A2Billing, Commercial Open Source Telecom Billing platform,
 * powered by Star2billing S.L. <http://www.star2billing.com/>
 *
 * @copyright   Copyright (C) 2004-2012 - Star2billing S.L.
 * @author      Anton Chmutov <chmutoff@yandex.ru>
 * @license     http://www.fsf.org/licensing/licenses/agpl-3.0.html
 * @package     A2Billing
 *
 * Software License Agreement (GNU Affero General Public License)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
**/

getpost_ifset(array('id', 'id_cc_card', 'mailbox', 'password', 'context', 'creationdate'));
if (empty($form_action) || $form_action=="list") {
	$HD_Form = new FormHandler("cc_voicemail_users");
} else {
	$HD_Form = new FormHandler("cc_voicemail_users");
}

$HD_Form -> FG_DEBUG = 0;
$HD_Form -> FG_TABLE_DEFAULT_ORDER = "mailbox";
$HD_Form -> FG_TABLE_DEFAULT_SENS = "DESC";

$HD_Form -> FG_TABLE_ID = 'cc_voicemail_users.id';

$HD_Form ->FG_LIST_ADDING_BUTTON1 = true;
$HD_Form ->FG_LIST_ADDING_BUTTON_LINK1 = "A2B_entity_voicemail.php?form_action=ask-add&section=".$_SESSION["menu_section"];
$HD_Form ->FG_LIST_ADDING_BUTTON_ALT1 = $HD_Form ->FG_LIST_ADDING_BUTTON_MSG1 = gettext("Add voicemail user");
$HD_Form ->FG_LIST_ADDING_BUTTON_IMG1 = Images_Path ."/world_add.png" ;

$HD_Form -> AddViewElement(gettext("ID"), "id", "3%", "center", "sort");
$HD_Form -> AddViewElement(gettext("CUSTOMER"), "id_cc_card", "10%", "center", "sort", "", "lie_link", "cc_card", "lastname, id, firstname", "id='%id'", "%1 %3", "", "A2B_entity_card.php");
$HD_Form -> AddViewElement(gettext("MAILBOX"), "mailbox", "10%", "center", "sort", "15");
$HD_Form -> AddViewElement(gettext("PASSWORD"), "password", "10%", "center", "sort", "15");
$HD_Form -> AddViewElement(gettext("CONTEXT"), "context", "10%", "center", "sort", "15");
$HD_Form -> AddViewElement(gettext("CALLERID"), "id_cc_card", "10%", "center", "sort", "", "lie", "cc_sip_buddies", "callerid, id", "id_cc_card='%id'", "%1", "", "");
$HD_Form -> AddViewElement(gettext("CREATION DATE"), "creationdate", "10%", "center", "sort", "16", "", "", "", "", "", "display_dateformat");


$HD_Form -> FieldViewElement ('id, id_cc_card, mailbox, password, context, id_cc_card AS callerid, creationdate');

$HD_Form -> FG_ACTION_SIZE_COLUMN = '15%';


$HD_Form -> CV_NO_FIELDS  = gettext("NO VOICEMAIL USERS HAVE BEEN CREATED!");
$HD_Form -> CV_DISPLAY_LINE_TITLE_ABOVE_TABLE = false;
$HD_Form -> CV_TEXT_TITLE_ABOVE_TABLE = '';
$HD_Form -> CV_DISPLAY_FILTER_ABOVE_TABLE = false;


$HD_Form -> FG_EDITION = true;
$HD_Form -> FG_DELETION = true;
$HD_Form -> FG_ADDITION = true;


if ($form_action!='ask-edit' && $form_action!='edit') {
	$HD_Form -> AddEditElement (gettext("CUSTOMER ID"),
		"id_cc_card",
		'',
		"POPUPVALUE",
		"size=30 maxlength=50",
		"4",
		gettext("Insert the Id Customer ID"),
		"" , "", "", "", "",
		"A2B_entity_card.php?popup_select=1&"
		, ", 'CardNumberSelection','width=550,height=350,top=20,left=100,scrollbars=1'" ,
		gettext("Set the Customer ID."));
}
	
$HD_Form -> AddEditElement (gettext("PASSWORD"),
	"password",
	'$value',
	"INPUT",
	"size=50 maxlength=120",
	"",
	gettext("Insert customer id"),
	"" , "", "", "", "" , "", "",
    gettext("Leave blank to use the default password"));
	
$HD_Form -> AddEditElement (gettext("CONTEXT"),
	"context",
	'$value',
	"INPUT",
	"size=50 maxlength=120",
	"",
	gettext("Insert customer id"),
	"" , "", "", "", "" , "", "",
    gettext("Leave blank for default context"));


if ($form_action!='ask-edit' && $form_action!='edit') {
	$HD_Form -> FieldEditElement ('id_cc_card, password, context');
} else {
	$HD_Form -> FieldEditElement ('password, context');
}

// Set the filter variables
$HD_Form -> FG_FILTER_APPLY = true;
$HD_Form -> FG_FILTERFIELD = 'mailbox';
$HD_Form -> FG_FILTERFIELDNAME = 'mailbox';

if (isset($filterprefix)  &&  (strlen($filterprefix)>0)) {
	if (strlen($HD_Form -> FG_TABLE_CLAUSE)>0) $HD_Form -> FG_TABLE_CLAUSE.=" AND ";
	$HD_Form -> FG_TABLE_CLAUSE .= "cc_voicemail_users.mailbox like '$filterprefix%'";
}

$HD_Form->FG_INSTANCE_NAME = 'voicemail user';
$HD_Form -> FG_INTRO_TEXT_EDITION= gettext("You can modify, through the following form, the different properties of your ".$HD_Form->FG_INSTANCE_NAME);
$HD_Form -> FG_INTRO_TEXT_ASK_DELETION = gettext("If you really want remove this")." ".$HD_Form->FG_INSTANCE_NAME.", ".gettext("click on the delete button.");
$HD_Form -> FG_INTRO_TEXT_ADD = gettext("you can add easily a new")." ".$HD_Form->FG_INSTANCE_NAME."<br>".gettext("Fill the following fields and confirm by clicking on the button add.");


$HD_Form -> FG_INTRO_TEXT_ADITION = '';
$HD_Form -> FG_TEXT_ADITION_CONFIRMATION = gettext("Your new")." ".$HD_Form->FG_INSTANCE_NAME." ".gettext("has been inserted. <br>");


$HD_Form -> FG_BUTTON_EDITION_SRC = $HD_Form -> FG_BUTTON_ADITION_SRC  = Images_Path . "/cormfirmboton.gif";
$HD_Form -> FG_BUTTON_EDITION_BOTTOM_TEXT = $HD_Form -> FG_BUTTON_ADITION_BOTTOM_TEXT = gettext("Click 'Confirm Data' to continue");


$HD_Form -> FG_ADDITIONAL_FUNCTION_AFTER_ADD = 'add_voicemail_mailbox';
//$HD_Form -> FG_ADDITIONAL_FUNCTION_AFTER_DELETE = 'did_destination_del';


$HD_Form -> FG_GO_LINK_AFTER_ACTION_ADD = filter_input(INPUT_SERVER, 'PHP_SELF', FILTER_SANITIZE_URL)."?id=";
$HD_Form -> FG_GO_LINK_AFTER_ACTION_EDIT = filter_input(INPUT_SERVER, 'PHP_SELF', FILTER_SANITIZE_URL)."?id=";
$HD_Form -> FG_GO_LINK_AFTER_ACTION_DELETE = filter_input(INPUT_SERVER, 'PHP_SELF', FILTER_SANITIZE_URL)."?id=";
