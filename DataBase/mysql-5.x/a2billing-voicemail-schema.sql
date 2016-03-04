CREATE TABLE `cc_voicemail_users` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `id_cc_card` int(11) unsigned NOT NULL,
  `mailbox` varchar(15) COLLATE utf8_bin NOT NULL DEFAULT '',
  `password` varchar(15) COLLATE utf8_bin NOT NULL DEFAULT '462434594854315',
  `context` varchar(50) COLLATE utf8_bin NOT NULL DEFAULT 'default',
  `creationdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_cc_card_unique` (`id_cc_card`),
  KEY `mailbox_context` (`mailbox`,`context`),
  KEY `id_cc_card_index` (`id_cc_card`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin;